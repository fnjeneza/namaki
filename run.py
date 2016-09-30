import yaml
from yowsup.registration import WACodeRequest

def foo():
    phone = None
    cc = None
    mcc = None
    mnc = None
    code = None



    with open("config.yml") as config:
        params = yaml.load(config)
        phone = params["phone"]
        cc = params["cc"]
        mcc = params["mcc"]
        mnc = params["mnc"]
        code = params["code"]


    if phone is None:
        print("phone is missing")

    if cc is None:
        print("cc is missing")

    if mcc is None:
        print("mcc is missing")

    if mnc is None:
        print("mnc is missing")

    if code is None:
        print("code missing")

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
        return (True, None)

def register(cc, phone, password):
    pass
