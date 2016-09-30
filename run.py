import yaml
from yowsup.registration import WACodeRequest, WARegRequest

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
        return (True, None)


