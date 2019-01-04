
#include "python_wrapping.h"

PyObject* toPyString(const char *buf)
{
#if PY_MAJOR_VERSION >= 3
  return PyUnicode_FromString(buf);
#else
  return PyString_FromString(buf);
#endif
}

char* fromPyString(PyObject * pyObj)
{
#if PY_MAJOR_VERSION >= 3
  return PyBytes_AsString(PyUnicode_AsUTF8String(pyObj));
#else
  return PyString_AsString(pyObj);
#endif
}

int checkPyString(PyObject * pyObj)
{
#if PY_MAJOR_VERSION >= 3
  return PyUnicode_Check(pyObj);
#else
  return PyString_Check(pyObj);
#endif
}

int checkPyBytes(PyObject * pyObj)
{
#if PY_MAJOR_VERSION >= 3
  return PyBytes_Check(pyObj)||PyByteArray_Check(pyObj);
#else
  return PyString_Check(pyObj)||PyByteArray_Check(pyObj);
#endif
}

char* fromPyBytes(PyObject * pyObj)
{
  if(PyByteArray_Check(pyObj))
    return PyByteArray_AsString(pyObj);
#if PY_MAJOR_VERSION >= 3
  if (PyBytes_Check(pyObj))
    return PyBytes_AsString(pyObj);
#else
  if (PyString_Check(pyObj))
    return PyString_AsString(pyObj);
#endif
  // error
  return 0;
}

int checkPyInt(PyObject * pyObj)
{
#if PY_MAJOR_VERSION >= 3
  return PyLong_Check(pyObj);
#else
  return PyInt_Check(pyObj) || PyLong_Check(pyObj);
#endif
}
