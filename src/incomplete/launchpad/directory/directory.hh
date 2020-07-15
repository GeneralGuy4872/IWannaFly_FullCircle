struct iwf::directory {
	std::map<std::string;iwf::directory> subdirectories;
	std::map<std::string;std::vector<unsigned char>> variables;
	/* the vector points to an untyped data block, and is used to
	 * allocate data on a bytewise basis.
	 */
	}

/* database files use a format consisting of a byte control code,
 * optionally followed by a sequence of pairs of size_t length specifiers
 * and strings of bytes containing data. currently, a database storing a
 * tree of iwf::directory would be as follows:
 *
 * SOH : enter a subdirectory (has one block of data for subdirectory name)
 * STX : begin an entry (has 2 blocks of data for variable name and
 *	variable data)
 * ETX : exit the current directory
 * DLE : begin an entry (has 2 blocks of data, but first block is an
 *	unsigned int instead of a size_t/byte array pair)
 *
 * directory trees are saved depth-first.
 */
