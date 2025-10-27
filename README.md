# tdjson [![Version](https://img.shields.io/pypi/v/tdjson?style=flat&logo=pypi)](https://pypi.org/project/tdjson) [![TDLib version](https://img.shields.io/badge/TDLib-v1.8.56-blue?logo=telegram)](https://github.com/tdlib/td) [![Downloads](https://static.pepy.tech/personalized-badge/tdjson?period=month&units=none&left_color=grey&right_color=brightgreen&left_text=Downloads)](https://pepy.tech/project/tdjson)

`tdjson` is a high-performance Python binding for [TDLib](https://github.com/tdlib/td)'s JSON interface. Outperforms `ctypes`, and **includes** `TDLib` for easy setup and use. Mainly created for [Pytdbot](https://github.com/pytdbot/client)

## Compatibility

`tdjson` is compatible with the following platforms:

*   **Linux** (`x86_64` and `aarch64`)
    *   Requires `glibc 2.17+`.
    *   Includes most modern distributions like:
        *   Debian 8+
        *   Ubuntu 13.10+
        *   Fedora 19+
        *   RHEL 7+
*   **Windows** (`x64`)
    *   Windows 10+

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
result = tdjson.td_execute(json.dumps({"@type": "getTextEntities", "text": "@telegram /test_command https://telegram.org telegram.me", "@extra": ["5", 7.0, "a"]}))
print(result)
```

For more detailed examples, check out the [examples](https://github.com/AYMENJD/tdjson/blob/main/examples) folder.

## License

MIT [LICENSE](https://github.com/AYMENJD/tdjson/blob/main/LICENSE)
