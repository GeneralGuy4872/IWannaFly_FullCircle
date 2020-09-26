class iwf::voxels::minichunk {
	private:
	std::map<uint16_t,uint16_t> data;
	public:
	int at (unsigned char x,unsigned char y,unsigned char z);
	int safe_at (unsigned char x,unsigned char y,unsigned char z);
	void insert (unsigned char x,unsigned char y,unsigned char z,uint16_t blockid);
	void erase (unsigned char x,unsigned char y,unsigned char z);
	};
