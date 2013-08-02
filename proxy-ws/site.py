from twisted.web import server, resource
from twisted.internet import reactor

from getproxy import GetProxy

site = server.Site(GetProxy())
reactor.listenTCP(8080, site)
reactor.run()
