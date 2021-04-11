from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer

authorizer = DummyAuthorizer()
authorizer.add_user("admin", "admin", "C:/ftp-server", perm="elradfmwM", msg_login="Login successful.", msg_quit="Goodbye.")
authorizer.add_user("user", "user", "C:/ftp-server/", perm="l", msg_login="Login successful.", msg_quit="Goodbye.")
authorizer.override_perm("user", "C:/ftp-server/anonym", perm="elr")
authorizer.override_perm("user", "C:/ftp-server/user", perm="elr")
authorizer.add_anonymous("C:/ftp-server/anonym", perm="elr", msg_quit="Goodbye.")

handler = FTPHandler
handler.authorizer = authorizer
server = FTPServer(("127.0.0.1", 21), handler)
server.serve_forever()