#include "ArgumentParser/ArgumentParser.h"
#include "Messenger/Messenger.h"
#include "Archiver/Archiver.h"
#include "Extractor/Extractor.h"

#include <fstream>

void MakeArchive(ArgumentParser& argument_parser, int argc) {
    try {
        std::ofstream archive(static_cast<std::string>(argument_parser.GetArchiveName()));

        Archiver archiver(archive);

        for (int i = 0; i < argc - 3; ++i) {
            std::string_view next_file_name = argument_parser.GetNextFileName();
            std::ifstream next_file(static_cast<std::string>(next_file_name));

            archiver.AddFile(next_file, next_file_name);

            next_file.close();
        }

        archiver.ArchiveEnd();
        archive.close();

        Messenger::SuccessArchiverMessage(argc - 3, argument_parser.GetArchiveName(), std::cout);
    } catch (const std::logic_error& error) {
        Messenger::ArchiverError(std::cout, error.what());
        exit(1);
    }
}

void ExtractArchive(ArgumentParser& argument_parser) {
    try {
        std::ifstream archive(static_cast<std::string>(argument_parser.GetArchiveName()));

        Extractor extractor(archive);

        size_t number_of_files = extractor.ExtractArchive();

        archive.close();

        Messenger::SuccessExtractorMessage(number_of_files, argument_parser.GetArchiveName(), std::cout);
    } catch (const std::logic_error& error) {
        Messenger::ExtractorError(std::cout, error.what());
        exit(1);
    }
}

int main(int argc, char** argv) {
    ArgumentParser argument_parser(argc, argv);

    if (argument_parser.IsCommandHelp()) {
        Messenger::Help(std::cout);
    } else if (argument_parser.IsCommandArchive()) {
        MakeArchive(argument_parser, argc);
    } else if (argument_parser.IsCommandExtract()) {
        ExtractArchive(argument_parser);
    } else {
        Messenger::UnknownCommandError(std::cout);
    }

    return 0;
}
