class TextMessage:
    def __init__(self,
            id=None,
            src=None,
            dest=None,
            timestamp=None,
            body=None):

        assert not (src and dest) , "set either 'src' or 'dest', not both"
        assert (src or dest), "'src' or 'dest' must be set"

        self._id = id
        self._src = src
        self._dest = dest
        self._timestamp = timestamp
        self._body = body

    def src(self):
        return self._src


    def src(self, src):
        self._src = src


    def dest(self, dest):
        self._dest = dest


    def dest(self, dest):
        self._to = dest
