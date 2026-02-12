#Networked Programs

#Parsing HTML and scraping the web

#using regex

import json
import ssl
import urllib.request
import re
import ssl
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE
url = input('Enter -')
html = urllib.request.urlopen(url, context = ctx).read()
#findall () specifies we only want the portion in the parenthesis
links = re.findall(b'href = "(http[s]?://.*?)"', html)
for link in links:
    print(link.decode())


#Real HTML is messy so BeautifulSoup library handles unclear HTML
#Not built in with python
from bs4 import BeautifulSoup

ctx = ssl._create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter- ')
html = urllib.request.urlopen(url, context = ctx).read()
soup = BeautifulSoup(html, 'html.parser')

tags = soup('a')
for tag in tags:
    print('TAG', tag)
    print('ADDRESS', tag.get('href', None))
    print('Contents', tag,contents[0])
    print('Attribute', tag.attr)


#Web services
#Data format XML, JSON

#XML
#<person>
#    <name> Chuck </name>
#    <phone type = "intl">
#      +1 734 303 4456
#    </phone>
#    <email hide = "yes" />
#</person>

import xml.etree.ElementTree as ET
data = '''
<person>
<name> Chuck </name>
<phone type = "intl">
+1 734 303 4456
</phone>
<email hide = "yes" />
</person>'''

tree = ET.fromstring(data)
print('Name:', tree.find('name').text)
print('Attr:', tree.find('email').get('hide'))

#can perform findall with specific tags and then loop through the list
import json
#JSON

data = '''
{
"name":"Chuck",
"phone":{
"type":"intl",
"number": "+1 734 303 4456"
},
"email":{
"hide":"yes"
}
}'''

info = json.loads(data) #will load as a list of lists or dict of dicts etc
print('User count:', len(info))

#API(application programming interface)
#set of contracts and rules for defining how you can get data from a service

#Service oriented application
#overall application makes use of the services of other applications





