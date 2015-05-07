// Copyright 2013 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef FILE_MEMFILE_INLINEFILE_H__
#define FILE_MEMFILE_INLINEFILE_H__

#include <string>

// Create a temporary file with the specified data. Return the file's name.
::std::string GetInlineFilename(const ::std::string& data);

#endif  // FILE_MEMFILE_INLINEFILE_H__
