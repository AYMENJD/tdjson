# tdjson

[![Version](https://img.shields.io/pypi/v/tdjson?style=flat&logo=pypi)](https://pypi.org/project/tdjson)
[![TDLib version](https://img.shields.io/badge/TDLib-v1.8.63-blue?logo=telegram)](https://github.com/tdlib/td)
[![Python Versions](https://img.shields.io/pypi/pyversions/tdjson?style=flat&logo=python)](https://pypi.org/project/tdjson)
[![Downloads](https://img.shields.io/pypi/dm/tdjson?style=flat&logo=pypi)](https://pypistats.org/packages/tdjson)

`tdjson` provides fast, native Python bindings for the JSON interface of [TDLib](https://github.com/tdlib/td).

It bundles prebuilt TDLib binaries, eliminating manual compilation and making it a reliable foundation for projects like [Pytdbot](https://github.com/pytdbot/client)

<a href="https://cupofton.pages.dev/donate?a=UQCeySURtYxvqF2jNXlsFrXuTEqPjJhGx8uoev6tUbD_HELL&n=AYMEN&t=1&c=You+deserve+a+Cup+of+TON+for+tdjson%2521" target="_blank" rel="noopener">
    <img src="https://cupofton.pages.dev/assets/badge-1.svg" alt="Buy me a Cup of TON" style="width: 600px; height: auto;">
</a>

## Compatibility

`tdjson` is compatible with the following platforms:

- **Linux** (`x64`, `ARM64`) — Debian 8+, Ubuntu 13.10+, Fedora 19+, RHEL 7+
- **Windows** (`x64`) — Windows 7+
- **macOS** (`M-series`) — macOS 11+

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
tdjson.td_send(client_id, json.dumps(request).encode("utf-8"))

# Receive updates or responses
response = tdjson.td_receive(10.0)
if response:
    print(response)

# Synchronously execute a TDLib request
result = tdjson.td_execute(
    json.dumps(
        {
            "@type": "getTextEntities",
            "text": "@telegram /test_command https://telegram.org telegram.me",
            "@extra": ["5", 7.0, "a"],
        }
    ).encode("utf-8")
)
print(result)
```

For more detailed examples, check out the [examples](https://github.com/AYMENJD/tdjson/blob/main/examples) folder.

## License

MIT [LICENSE](https://github.com/AYMENJD/tdjson/blob/main/LICENSE)
