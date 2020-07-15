typedef std::vector<unsigned char> variablewidthdatablock;

int variablewidthdatablock_write (FILENO file,variablewidthdatablock * datablock);
int variablewidthdatablock_read (FILENO file,variablewidthdatablock * emptyblock);
