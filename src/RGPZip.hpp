/*
 -----------------------------------------------------------------------------------------------------------------------
 The MIT License (MIT)

 Copyright (c) 2018 Ralph-Gordon Paul. All rights reserved.

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
 persons to whom the Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 -----------------------------------------------------------------------------------------------------------------------
 */

#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <vector>

namespace rgp
{
class Zip
{
  public:
    explicit Zip();
    ~Zip();

    // accessors
    std::shared_ptr<std::vector<std::string>> unzippedFiles() const;

    // zip
    bool createZipFile(const std::string &filepath, bool append = false, const std::string &password = "");
    bool addFileToZip(std::string &filepath, std::string &newname);
    bool addDataToZip(std::vector<uint8_t> &data, std::string newname,
                      std::chrono::system_clock::time_point created = std::chrono::system_clock::now());
    bool closeZipFile();

    // unzip
    bool openUnzipFile(const std::string &filepath, const std::string &password = "");
    bool unzipFiles(const std::string &targetpath, bool overwrite = false);
    bool closeUnzipFile();

  private:
    Zip(const Zip &other) = delete;

    std::string _password;
    std::shared_ptr<std::vector<std::string>> _unzippedFiles{nullptr};

    void *_zipFile{nullptr};
    void *_unzipFile{nullptr};
};

}  // namespace rgp