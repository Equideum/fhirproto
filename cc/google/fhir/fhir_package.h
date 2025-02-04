// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_FHIR_FHIR_PACKAGE_H_
#define GOOGLE_FHIR_FHIR_PACKAGE_H_

#include "absl/container/flat_hash_map.h"
#include "absl/status/statusor.h"
#include "absl/types/optional.h"
#include "proto/google/fhir/proto/profile_config.pb.h"
#include "proto/google/fhir/proto/r4/core/resources/code_system.pb.h"
#include "proto/google/fhir/proto/r4/core/resources/search_parameter.pb.h"
#include "proto/google/fhir/proto/r4/core/resources/structure_definition.pb.h"
#include "proto/google/fhir/proto/r4/core/resources/value_set.pb.h"

namespace google::fhir {

// Struct representing a FHIR Proto package, including defining resources and a
// PackageInfo proto. This is constructed from a zip file containing these
// files, as generated by the `fhir_package` rule in protogen.bzl.
// TODO: Support versions other than R4
struct FhirPackage {
  proto::PackageInfo package_info;
  std::vector<google::fhir::r4::core::StructureDefinition>
      structure_definitions;
  std::vector<google::fhir::r4::core::SearchParameter> search_parameters;
  std::vector<google::fhir::r4::core::CodeSystem> code_systems;
  std::vector<google::fhir::r4::core::ValueSet> value_sets;

  static absl::StatusOr<FhirPackage> Load(absl::string_view zip_file_path);

  // This Load variant will use the passed-in PackageInfo proto for the
  // FhirPackage, regardless of whether or not one was found in the zip.
  static absl::StatusOr<FhirPackage> Load(
      absl::string_view zip_file_path, const proto::PackageInfo& package_info);

 private:
  FhirPackage() {}
  static absl::StatusOr<FhirPackage> Load(
      absl::string_view zip_file_path,
      const absl::optional<proto::PackageInfo> optional_package_info);
};

}  // namespace google::fhir

#endif  // GOOGLE_FHIR_FHIR_PACKAGE_H_
