std::vector<std::string> slurplines (char * filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::vector<std::string> output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp);
		output.push_back(tmp);
		}
	return output;
	}

std::vector<std::string> slurplines (std::string filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::vector<std::string> output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp);
		output.push_back(tmp);
		}
	return output;
	}

std::vector<std::string> slurpstrings (char * filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::vector<std::string> output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp,0);
		output.push_back(tmp);
		}
	return output;
	}

std::vector<std::string> slurpstrings (std::string filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::vector<std::string> output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp,0);
		output.push_back(tmp);
		}
	return output;
	}

std::vector<std::string> slurprecord (char * filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::vector<std::string> output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp,036);
		output.push_back(tmp);
		}
	return output;
	}

std::vector<std::string> slurprecord (std::string filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::vector<std::string> output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp,036);
		output.push_back(tmp);
		}
	return output;
	}

std::string slurpfile (char * filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::string output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp);
		output.append(tmp);
		output.append("\n");
		}
	return output;
	}

std::string slurpfile (std::string filename) {
	std::ifstream input;
	input.open(filename,std::ifstream::in);
	std::string output;
	for (std::string tmp;!(input.eof());) {
		getline(input,tmp);
		output.append(tmp);
		output.append("\n");
		}
	return output;
	}
