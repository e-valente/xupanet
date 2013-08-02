from random import choice

from twisted.web import resource


class GetProxy(resource.Resource):
    
    #isLeaf = True
    
    def getChild(self, name, request):
        if name == 'proxy':
            return self
        return Resource.getChild(self, name, request)

    def render_GET(self, request):
        with open('list.txt', 'r') as fp:
            lst_proxy = fp.readlines()
            proxy_addr = choice(lst_proxy)

        # Deals with whitespace 
        proxy_addr = proxy_addr.replace(' ', '')
        context = {
            'proxy': proxy_addr,
        }

        template = "<html>{proxy}</html>"
 
        return template.format(**context)


resource = GetProxy()

