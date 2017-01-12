import serial, requests

serial = serial.Serial('COM3', 9600)

url = 'http://192.168.2.4:3000/api/'
cred = {
    'username' : 'system',
    'password' : 'cricket'
    }

res = requests.post(url + 'login', data=cred)
print res.headers
print res.url
print res.json()
headers = {
    'X-Auth-Token' : res.json()['data']['authToken'],
    'X-User-Id' : res.json()['data']['userId']
    }

while True:
    str = serial.readline()
    print str
    data = {
        'temp' : str.split(',')[1].strip(),
        'humidity' : str.split(',')[0].strip()
        }
    print data

    res = requests.post(url + 'climate_data', data=data)
    print res.url
    print res
