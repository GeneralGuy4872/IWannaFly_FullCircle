#ifdef __cplusplus
extern "C" {
#endif

extern int iwf$$voxels$$minichunk$$at (void * opaque,unsigned char x,unsigned char y,unsigned char z);
extern int iwf$$voxels$$minichunk$$safe_at (void * opaque,unsigned char x,unsigned char y,unsigned char z);
extern IMPLICIT iwf$$voxels$$minichunk$$insert (void * opaque,unsigned char x,unsigned char y,unsigned char z,uint16_t blockid);
extern IMPLICIT iwf$$voxels$$minichunk$$erase (void * opaque,unsigned char x,unsigned char y,unsigned char z);

#ifdef __cplusplus
}
#endif
