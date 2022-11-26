#include <cstring>
#include <fstream>
#include <iostream>
#include <string_view>

struct Configuration
{
    std::string filename;
    bool useStdin{};
    bool isConfigured{};
};

bool streq(const std::string_view a, const std::string_view b)
{
    return a.compare(b) == 0;
}

Configuration getConfigurationFromCommandline(const int argc, const char **argv)
{
    Configuration config{};

    for (auto i = 1; i < argc; i++)
    {
        if (streq(argv[i], "-stdin"))
        {
            config.useStdin = true;
            config.isConfigured = true;
        }
        else
        {
            config.filename = argv[i];
            config.isConfigured = true;
        }
    }

    return config;
}

int main(int argc, const char **argv)
{
    std::locale loc("en_US.UTF-8");
    std::locale::global(loc);

    // global_start_timer();

    const auto config = getConfigurationFromCommandline(argc, argv);

    if (!config.isConfigured)
    {
        std::cout << "Commandline arguments expected\n";
        return 1;
    }

    if (!config.useStdin)
    {
        std::fstream fs;
        fs.open(config.filename, std::fstream::in);

        // AsmParser::AssemblyTextParser parser(config.filter);
        // parser.fromStream(fs);
        // if (config.doDebugDump) {
        //     std::fstream fdebug;
        //     fdebug.open("./asm-parser-debugdump.json", std::fstream::out);
        //     parser.outputDebugJson(fdebug);
        // }

        // if (config.outputText) {
        //     parser.outputText(std::cout);
        // } else {
        //     parser.outputJson(std::cout);
        // }
    }
    else
    {
        // AsmParser::AssemblyTextParser parser(config.filter);
        // parser.fromStream(std::cin);

        // if (config.outputText) {
        //     parser.outputText(std::cout);
        // } else {
        //     parser.outputJson(std::cout);
        // }
    }

    return 0;
}
