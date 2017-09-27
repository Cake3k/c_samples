#ifndef COMMON_H
#define COMMON_H

/**
 * Lists all files in given subdirectory, 
 * with given filetype. 
 * @param[in]  dirname  Name of subdirectory (e.g. txtfiles)
 * @param[in]  filetype Filetype (e.g. ".txt")
 * @return     True: Directory opened successfully.
 * 
 * Example:
 * char *dirname = "./txtfiles";
 * char *ftype = ".txt";
 * bool readconf = listfiles(&dirname, &ftype);
 */
bool listfiles(char *dirname[], char *filetype[]);


#endif