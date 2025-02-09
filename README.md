# tdjson [![Version](https://img.shields.io/pypi/v/Tdjson?style=flat&logo=pypi)](https://pypi.org/project/Tdjson) [![TDLib version](https://img.shields.io/badge/TDLib-v0.0.0-blue?logo=telegram)](https://github.com/tdlib/td) [![Downloads](https://static.pepy.tech/personalized-badge/tdjson?period=month&units=none&left_color=grey&right_color=brightgreen&left_text=Downloads)](https://pepy.tech/project/tdjson)

`tdjson` is a high-performance Python binding for [TDLib](https://github.com/tdlib/td)'s JSON interface. Outperforms `ctypes`, and **includes** TDLib for easy setup and use

## Compatibility

`tdjson` is compatible with almost all Linux `x86_64` distributions that use `glibc 2.17+`. This includes most modern Linux distributions:

- Debian 8+
- Ubuntu 13.10+
- Fedora 19+
- RHEL 7+

## Installation

You can install `tdjson` directly from PyPI:

```bash
pip install tdjson
```

## Usage

Here’s a quick example to get you started:

```python
import json
import tdjson

# Create a new TDLib client
client_id = tdjson.td_create_client_id()

# Send a request to TDLib
request = {"@type": "getOption", "name": "version"}
tdjson.td_send(client_id, json.dumps(request))

# Receive updates or responses
response = tdjson.td_receive(10.0)
print(response)

# Synchronously execute a TDLib request
result = tdjson.td_execute(json.dumps({"@type": "getTextEntities", "text": "Hello, world! #tdlib $SAR"}))
print(result)
```

## License

MIT [LICENSE](https://github.com/AYMENJD/tdjson/blob/main/LICENSE)
