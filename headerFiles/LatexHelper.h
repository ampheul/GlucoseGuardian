#include <string>
/** \brief Generate latex strings
 *  \author Thomas
 * 
 *  Generate latex strings for use with writing latex code automatically.
 * */
namespace LatexHelper
{
      /**
       * \brief Environemnt
       * \param environment the environment
       * \param text the string to use
       * \return string of environemnt
       *
       * Sets up environment
       */
    std::string environment(std::string environment, std::string text);

      /**
       * \brief Returns end portion of string
       * \param environment the environment
       * \return the end portion
       *
       * Sets up end portion to use
       */
    std::string end(std::string environment);

     /**
       * \brief Returns beginning portion of string
       * \param environment the environment
       * \return the starting portion
       *
       * Sets up beginning portion to use
       */
    std::string begin(std::string environment);


     /**
       * \brief Returns header for latex
       * \return the header
       *
       * Sets up header portion to use
       */
    std::string header();

      /**
       * \brief Returns input file info
       * \return the input file info
       *
       * Sets up input info portion to use
       */
    std::string input(std::string inputFile);
    
    /** 
     * \brief Returns a string for a latex command.
     * 
     * \return a string for a latex command in the form 
     *      \newcommand{\[command]}{\[definition]}
     * where [command] and [definition] are replaced with the respective arguments.
     * */
    std::string newCommand(
        /// Command to create
        std::string command,
        /// Definition of the command
        std::string definition);
}