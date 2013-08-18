
 :: DOCS ::
http://twistedmatrix.com/trac/wiki/Downloads
http://twistedmatrix.com/documents/13.0.0/web/howto/using-twistedweb.html

On OpenSuse, set your python path:
PYTHONPATH=/usr/lib64/python2.7/site-packages/twisted

 :: RUNNING :: 
# twistd -n web --path . # for DEBUG
python site.py

The server will run on localhost:8080
