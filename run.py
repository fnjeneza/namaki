import yaml
from yowsup.registration import WACodeRequest, WARegRequest
from yowsup.stacks import YowStackBuilder
from yowsup.layers.axolotl.props import PROP_IDENTITY_AUTOTRUST
from yowsup.layers import YowLayerEvent
from yowsup.layers.auth import AuthError
from yowsup.layers.network import YowNetworkLayer
from layer import NamakiLayer
from threading import Thread
import time

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
            config["login"] = result["login"]
            yaml.dump(config, config_file)
        return (True, None)
"""
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
        self.stack.setProp(PROP_IDENTITY_AUTOTRUST, True)

    def start(self):
        print("starting...")
        self.stack.broadcastEvent(YowLayerEvent(YowNetworkLayer.EVENT_STATE_CONNECT))

        try:
            self.stack.loop()
        except AuthError as e:
            print("AuthError reason %s" % e)
"""

if __name__ == "__main__":
    credentials = None

    with open(CONFIG_FILE) as config_file:
        config = yaml.load(config_file)
        login = config["login"]
        pw = config["pw"]
        assert login is not None, "login must not be empty"
        assert pw is not None, "pw must no be empty"
        credentials = (login, pw)

    stackBuilder = YowStackBuilder()

    stack = stackBuilder.pushDefaultLayers(True)\
            .push(NamakiLayer)\
            .build()

    stack.setCredentials(credentials)
    stack.broadcastEvent(YowLayerEvent(YowNetworkLayer.EVENT_STATE_CONNECT))
    t = Thread(target=stack.loop)
    t.start()
    layer = stack.getLayer(-1)
    layer.send_message("33780889335", "test")
    print("bye gonna sleep")
    time.sleep(5)
    layer.send_message("33780889335", "test")
    print("hello")
