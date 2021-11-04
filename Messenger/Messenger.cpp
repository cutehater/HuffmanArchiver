#include "Messenger.h"

void Messenger::Help(std::ostream& output_stream) {
    output_stream
            << "This is console archiver/extractor by @cutehater based on Huffman coding\n"
               "\n"
               "Usage: archiver -c archive_name file1 [file2 ...]   archive file1 file2 and save to archive_name\n"
               "       archiver -d archive_name                     extract files from archive_name to current "
               "directory\n"
               "       archiver -h                                  print help\n\n";
}

void Messenger::UnknownCommandError(std::ostream& output_stream) {
    output_stream << "Error: unknown command\n"
                     "Please try \'archiver -h\' for more information\n";
}

void Messenger::ExtractorError(std::ostream& output_stream, std::string error_information) {
    output_stream << "Error: " + error_information +
                     "\n"
                     "Extracting the archive failed\n";
}

void Messenger::ArchiverError(std::ostream& output_stream, std::string error_information) {
    output_stream << "Error: " + error_information +
                     "\n"
                     "Archiving the files failed\n";
}

void Messenger::SuccessArchiverMessage(const size_t number_of_files, const std::string_view archive_name,
                                       std::ostream& output_stream) {
    output_stream << "Successfully archived " << number_of_files << " file" << (number_of_files == 1 ? "" : "s")
                  << " to " << archive_name << "\n";
}

void Messenger::SuccessExtractorMessage(const size_t number_of_files, const std::string_view archive_name,
                                        std::ostream& output_stream) {
    output_stream << "Successfully extracted " << number_of_files << " file" << (number_of_files == 1 ? "" : "s")
                  << " from " << archive_name << "\n";
}