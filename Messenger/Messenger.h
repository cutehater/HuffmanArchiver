#pragma once

#include <iostream>

class Messenger {
public:
    Messenger() = default;

    static void Help(std::ostream& output_stream);

    static void UnknownCommandError(std::ostream& output_stream);
    static void ExtractorError(std::ostream& output_stream, std::string error_information);
    static void ArchiverError(std::ostream& output_stream, std::string error_information);

    static void SuccessArchiverMessage(const size_t number_of_files, const std::string_view archive_name,
                                       std::ostream& output_stream);
    static void SuccessExtractorMessage(const size_t number_of_files, const std::string_view archive_name,
                                        std::ostream& output_stream);
};