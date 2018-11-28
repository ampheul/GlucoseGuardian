#include <string>
/** Generate latex strings
 * 
 * Generate latex strings for use with writing latex code automatically.
 * */
namespace LatexHelper
{
    std::string environment(std::string environment, std::string text);
    std::string end(std::string environment);
    std::string begin(std::string environment);
    std::string header();
    /** Returns a string for a latex command.
     * 
     * Returns a string for a latex command in the form 
     *      \newcommand{\[command]}{\[definition]}
     * where [command] and [definition] are replaced with the respective arguments.
     * */
    std::string newCommand(
        /// Command to create
        std::string command,
        /// Definition of the command
        std::string definition);
}