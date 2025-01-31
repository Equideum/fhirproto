load(
    "@rules_python//python:python.bzl",
    "py_library",
    "py_test",
)
load("@fhir_bazel_pip_dependencies//:requirements.bzl", "requirement")

package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])

py_library(
    name = "primitive_time_utils",
    srcs = [
        "__init__.py",
        "_primitive_time_utils.py",
    ],
    srcs_version = "PY3",
    visibility = ["//py/google/fhir:__subpackages__"],
    deps = [
        "@com_google_protobuf//:protobuf_python",
        "//py",
        "//py/google/fhir/utils:proto_utils",
        requirement("backports.zoneinfo"),
        requirement("python-dateutil"),
        requirement("six"),
    ],
)

py_library(
    name = "codes",
    srcs = [
        "__init__.py",
        "codes.py",
    ],
    srcs_version = "PY3",
    deps = [
        ":fhir_errors",
        "//py",
        "//proto/google/fhir/proto:annotations_py_pb2",
        "//py/google/fhir/utils:annotation_utils",
        "//py/google/fhir/utils:fhir_types",
        "//py/google/fhir/utils:proto_utils",
        "@com_google_protobuf//:protobuf_python",
    ],
)

py_library(
    name = "extensions",
    srcs = [
        "__init__.py",
        "extensions.py",
    ],
    srcs_version = "PY3",
    deps = [
        ":codes",
        ":fhir_errors",
        "//py",
        "//proto/google/fhir/proto:annotations_py_pb2",
        "//py/google/fhir/utils:annotation_utils",
        "//py/google/fhir/utils:fhir_types",
        "//py/google/fhir/utils:proto_utils",
        "@com_google_protobuf//:protobuf_python",
    ],
)

py_library(
    name = "fhir_errors",
    srcs = [
        "__init__.py",
        "fhir_errors.py",
    ],
    srcs_version = "PY3",
    deps = ["//py"],
)

py_library(
    name = "primitive_handler",
    srcs = [
        "__init__.py",
        "primitive_handler.py",
    ],
    srcs_version = "PY3",
    deps = [
        "//py",
        "//py/google/fhir:primitive_time_utils",
        "//py/google/fhir/json_format/wrappers:primitive_wrappers",
        "@com_google_protobuf//:protobuf_python",
    ],
)

py_library(
    name = "references",
    srcs = [
        "__init__.py",
        "references.py",
    ],
    srcs_version = "PY3",
    deps = [
        "//py",
        "//py/google/fhir/utils:annotation_utils",
        "//py/google/fhir/utils:path_utils",
        "//py/google/fhir/utils:proto_utils",
        "@com_google_protobuf//:protobuf_python",
    ],
)

py_library(
    name = "resource_validation",
    srcs = [
        "__init__.py",
        "resource_validation.py",
    ],
    srcs_version = "PY3",
    deps = [
        ":fhir_errors",
        ":primitive_handler",
        "//py",
        "//proto/google/fhir/proto:annotations_py_pb2",
        "//py/google/fhir:primitive_time_utils",
        "//py/google/fhir/utils:annotation_utils",
        "//py/google/fhir/utils:fhir_types",
        "//py/google/fhir/utils:proto_utils",
        "@com_google_protobuf//:protobuf_python",
    ],
)

py_library(
    name = "terminology_service_client",
    srcs = [
        "__init__.py",
        "terminology_service_client.py",
    ],
    srcs_version = "PY3",
    deps = [
        "//py",
        "//proto/google/fhir/proto/r4/core/resources:value_set_py_pb2",
        "//py/google/fhir/r4:json_format",
        requirement("requests"),
    ],
)

py_library(
    name = "value_sets",
    srcs = [
        "__init__.py",
        "value_sets.py",
    ],
    srcs_version = "PY3",
    deps = [
        ":terminology_service_client",
        "//py",
        "//proto/google/fhir/proto/r4/core/resources:structure_definition_py_pb2",
        "//proto/google/fhir/proto/r4/core/resources:value_set_py_pb2",
        "//py/google/fhir/utils:fhir_package",
        requirement("sqlalchemy"),
    ],
)

py_library(
    name = "extensions_test",
    testonly = 1,
    srcs = [
        "__init__.py",
        "extensions_test.py",
    ],
    srcs_version = "PY3",
    deps = [
        ":extensions",
        "@com_google_protobuf//:protobuf_python",
        "//py",
        "//py/google/fhir/testing:testdata_utils",
        requirement("absl-py"),
        requirement("six"),
    ],
)

py_library(
    name = "primitive_handler_test",
    testonly = 1,
    srcs = [
        "__init__.py",
        "primitive_handler_test.py",
    ],
    srcs_version = "PY3",
    deps = [
        ":primitive_handler",
        "@com_google_protobuf//:protobuf_python",
        "//py",
        "//py/google/fhir:extensions",
        "//py/google/fhir:fhir_errors",
        "//py/google/fhir:primitive_time_utils",
        "//py/google/fhir/testing:testdata_utils",
        "//py/google/fhir/utils:path_utils",
        "//py/google/fhir/utils:proto_utils",
        requirement("absl-py"),
        requirement("six"),
    ],
)

py_test(
    name = "fhir_errors_test",
    srcs = ["fhir_errors_test.py"],
    legacy_create_init = 0,
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":fhir_errors",
        "//py",
        requirement("absl-py"),
        requirement("six"),
    ],
)

py_test(
    name = "terminology_service_client_test",
    srcs = ["terminology_service_client_test.py"],
    legacy_create_init = 0,
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":terminology_service_client",
        "//py",
        "//proto/google/fhir/proto/r4/core/resources:value_set_py_pb2",
        requirement("absl-py"),
    ],
)

py_test(
    name = "value_sets_test",
    srcs = ["value_sets_test.py"],
    data = [
        "//spec:fhir_r4_package.zip",
    ],
    legacy_create_init = 0,
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":terminology_service_client",
        ":value_sets",
        "//py",
        "//proto/google/fhir/proto/r4/core:datatypes_py_pb2",
        "//proto/google/fhir/proto/r4/core/resources:structure_definition_py_pb2",
        "//proto/google/fhir/proto/r4/core/resources:value_set_py_pb2",
        "//py/google/fhir/utils:fhir_package",
        requirement("absl-py"),
        requirement("six"),
        requirement("sqlalchemy"),
    ],
)
