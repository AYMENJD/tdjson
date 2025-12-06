#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <optional>
#include <td/telegram/td_json_client.h>

namespace nb = nanobind;
using bytes = nb::bytes;

void send(int client_id, bytes request) { td_send(client_id, request.c_str()); }

std::optional<bytes> receive(double timeout) {
  const char *result;

  {
    nb::gil_scoped_release release;
    result = td_receive(timeout);
  }

  if (!result) {
    return std::nullopt;
  }

  return bytes(result);
}

std::optional<bytes> execute(bytes request) {
  const char *result;

  {
    nb::gil_scoped_release release;
    result = td_execute(request.c_str());
  }

  if (!result) {
    return std::nullopt;
  }

  return bytes(result);
}

NB_MODULE(tdjson_ext, m) {
  m.def("td_create_client_id", &td_create_client_id,
        nb::call_guard<nb::gil_scoped_release>(),
        "Returns an opaque identifier of a new TDLib instance")
      .def("td_send", &send, nb::call_guard<nb::gil_scoped_release>(),
           nb::arg("client_id"), nb::arg("request"),
           "Sends request to the TDLib client. May be called from any thread")
      .def(
          "td_receive", &receive, nb::arg("timeout"),
          "Receives incoming updates and request responses. Must not be called "
          "simultaneously from two different "
          "threads")
      .def("td_execute", &execute, nb::arg("request"),
           "Synchronously executes a TDLib request");
}
