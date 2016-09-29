import yaml

params = {}

with open("config.yml") as config:
    params = yaml.load(config)

if params["phone"] is None:
    print("phone is missing")

if params["cc"] is None:
    print("cc is missing")

if params["mcc"] is None:
    print("mcc is missing")

if params["mnc"] is None:
    print("mnc is missing")

if params["code"] is None:
    print("code is missing")
