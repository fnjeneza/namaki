import yaml
from yowsup.registration import WACodeRequest

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

    #request code
    request_code = WACodeRequest(cc, phone, mcc, mnc, mcc, mnc)
    result = request_code.send()

    print(result)

else:
    #register
    pass
