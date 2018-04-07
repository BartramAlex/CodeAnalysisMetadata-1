/*
  @file code_analysis.cpp

  Implementation of analysis requests
*/

#include "code_analysis.hpp"
#include "get_language_from_filename.hpp"
#include <iostream>

#include <string>

/** Generate source analysis based on the request
 * @param request Data that forms the request
 * @retval true   Valid request
 * @retval false  Invalid filename or unable to deduce language
 */
bool code_analysis(const analysis_request& request) {

    auto filename = analysis_filename(request);

    auto url = analysis_url(request);

    auto language = analysis_language(request, filename);

    // code analysis processing that is not yet implemented

	
	if(language==""){
		if(request.given_filename == "-" ){
				std::cout << "ERROR: Using stdin requires a declared language" << std::endl; 
		}
		else { 	std::cout << "ERROR: Extension not supported" << std::endl; }
	}

    return false;
}

/** Filename extracted from the request
 * @param  request Data that forms the request
 * @retval filename
 */
std::string analysis_filename(const analysis_request& request) {
	std::string fName = "";	
	if(request.option_filename != ""){
		fName = request.option_filename;
	}
	else if(request.option_filename == ""){

		if(request.given_filename == "-"){
			if(request.entry_filename == "data"){ fName = request.option_filename; }
			else { fName = request.entry_filename; }
		}

		else if(request.entry_filename == "data"){
			fName = request.given_filename;
		}

	}
	
	//implement filename validity test later
	//std::cout << "Valid Filename\t Designated Filename: " << request.option_filename << std::endl;
	
    return fName;
}

/** URL extracted from the request
 * @param  request Data that forms the request
 * @retval URL
 */
std::string analysis_url(const analysis_request& request) {
    
    std::string URL = "";	
	if(request.option_url != ""){
		URL = request.option_url;
	}
	else if(request.option_url == ""){
		URL = request.given_url;
	}

    return URL;
}

/** Language extracted from the request and the filename
 * @param  request Data that forms the request
 * @param  filename Filename extracted from the request
 * @retval language
 */
std::string analysis_language(const analysis_request& request, const std::string& filename) {
	
	std::string lang = "";	
	if(request.option_language != ""){
		lang = request.option_language;
	}
	else if(request.option_language == ""){
		lang = get_language_from_filename(filename);
	}

    return lang;
}
