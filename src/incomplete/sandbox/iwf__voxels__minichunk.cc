class iwf::voxels::minichunk {
	public:
		void set(unsigned x,
		std::map<uint16_t,uint16_t> data;
	}

uint16_t iwf::voxels::minichunk::at (uint8_t x,uint8_t y,uint8_t z) {
	if ((x < 0x10) && (y < 0x10) && (x < 0x10)) {
		uint16_t output;
		try {
			output = self.at((z << 8)|(y << 4)|x);
		} catch (out_of_range) {
			return 0;
			}
		return output;
	} else {
		errno = EINVAL;
		return 0;
		}}

int iwf::voxels::minichunk::emplace (uint8_t x,uint8_t y,uint8_t z,uint16_t blockid) {
	if ((x < 0x10) && (y < 0x10) && (x < 0x10)) {
		iwf::voxels::minichunk::data::iterator exists = this.data.find((z << 8)|(y << 4)|(x));
		if (exists == this.data.end()) {
			this.data.emplace(((z << 8)|(y << 4)|x),blockid);
			return 0;
		} else {
			exists->second = blockid;
			return 0;
			}		
	} else {
		errno = EINVAL;
		return -1;
		}}

void iwf::voxels::minichunk::erase (uint8_t x,uint8_t y,uint8_t z) {
	if ((x < 0x10) && (y < 0x10) && (x < 0x10)) {
		iwf::voxels::minichunk::data::iterator exists = this.data.find((z << 8)|(y << 4)|(x));
		if (exists != this.data.end()) {
			this.data.erase(exists);
			//and now it doesn't
			}}}
