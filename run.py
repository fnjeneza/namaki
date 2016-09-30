import yaml
from yowsup.registration import WACodeRequest, WARegRequest
from yowsup.stacks import YowStackBuilder
from yowsup.layers.axolotl.props import PROP_IDENTITY_AUTOTRUST
from yowsup.layers import YowLayerEvent
from yowsup.layers.auth import AuthError
from layer import NamakiLayer

CONFIG_FILE = "config"

def request_code(cc, phone, mcc, mnc):
    """
    send a request for code
    """
    #request code
    req_code = WACodeRequest(cc, phone, mcc, mnc, mcc, mnc)
    result = req_code.send()
    print(result)

    if result["status"] == "fail":
        return (False, result["reason"])

    else:
        config = { "cc": cc,
                "phone": phone,
                "mcc": mcc,
                "mnc": mnc}

        #config file name is config
        with open(CONFIG_FILE, "w") as config_file:
            yaml.dump(config, config_file)

        return (True, None)

def register(code):
    config = None
    code = code.replace('-', '')

    with open(CONFIG_FILE) as config_file:
        config = yaml.load(config_file)

    req = WARegRequest(config["cc"], config["phone"], code)
    result = req.send()
    print(result)

    if result["status"] == "fail":
        return (False, result["reason"])

    else:
        with open(CONFIG_FILE, "w") as config_file:
            config["pw"] = result["pw"]
            config["loging"] = result["login"]
            yaml.dump(config, config_file)
        return (True, None)

class NamakiStack(object):
    def __init__(self):
        stackBuilder = YowStackBuilder()

        self.stack = stackBuilder\
                .pushDefaultLayers(True)\
                .push(NamakiLayer)\
                .build()

        credentials = None

        with open(CONFIG_FILE) as config_file:
            config = yaml.load(config_file)
            login = config["login"]
            pw = config["pw"]
            assert login is not None, "login must not be empty"
            assert pw is not None, "pw must no be empty"
            credentials = (login, pw)


        self.stack.setCredentials(credentials)
        self.stack.setProp(PROP_IDENTITY_AUTOTRUST)

    def start(self):
        print("starting...")
        self.stack.broadcastEvent(YowLayerEvent(NamakiLayer.EVENT_START))

        try:
            self.stack.loop()
        except AuthError as e:
            print("AuthError reason %s" % e)
