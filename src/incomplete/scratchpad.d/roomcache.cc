/* this is a C++-enabled simplification of one of the oldest and most complex bespoke automata in the engine; wide format view
 * (132 col) is recommended.
 *
 * it is currently modeled after that datastructure, but may be optimized in a future version of the engine
 *
 * UNDER NO CIRCUMSTANCES SHOULD THIS BE ACCESSED MANUALLY.
 * doing so can potentially cause the engine to enter a corrupt state, and cause permenant damage to save files. additionally,
 * the internal functionality of the object should not be implied to provide a stable API guaruntee, meaning that potentially
 * breaking changes may happen frequently and with no more warning than a footnote in the EXTENDED changelog.
 *
 * think of this object as a system daemon. you alter it's data, not directly, but by making a request; requests take the form
 * of API functions in this case.
 *
 * DRAGONS DWELL HERE
 */

#define IMPORT___IWF__CONSTANTS__CHUNK__NEIGHBOR
※include "chunk.H"

#define IWF__CHUNKCACHE__WARP_TYPES 16
#define IWF__CHUNKCACHE__UNDOWARP_LEVELS 8
#define IWF__CHUNKCACHE__STALECACHE_DEPTH 64

namespace iwf::roomcache {
	std::map<int64_t;std::pair<iwf::datatypes::chunk_t *;int>> data;

	int64_t current[5][5][5] = {
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1};

	std::vector<int64_t> warpbank;
	std::vector<int64_t> undowarpbank;

	namespace stalecache {
		std::list<int64_t> data;
		std::map<int64_t;std::list<int64_t>::iterator> index;
		}

	SYSINT load (int64_t input) {
		int64_t old[7][7][7];
		memcpy(&old,&(iwf::roomcache::current),sizeof(int64_t) * 7 * 7 * 7);
		memset(&(iwf::roomcache::current),-1,sizeof(int64_t) * 7 * 7 * 7);

		//HERE BE DRAGONS
		#include "reload_rooms.inc"

	SYSINT unload (int64_t dead) {
		if (iwf::roomcache::data[dead].second < 0) {
			free(iwf::roomcache::data[dead].first);
			iwf::roomcache::data.erase(dead);
			return 0;
		} else {
			return 1;
		}}

	SYSINT queueforunload (int64_t input) {
		if (iwf::roomcache::data[input].second < 0) {
			iwf::roomcache::stalecache::data.push_front(int64_t);
			iwf::roomcache::stalecache::index[input] = iwf::roomcache::stalecache::data.begin()
			while (iwf::roomcache::stalecache::data.size() > IWF__CHUNKCACHE__STALECACHE_DEPTH) {
				iwf::roomcache::stalecache::index.erase(iwf::roomcache::stalecache::data.back());
				iwf::roomcache::unload(iwf::roomcache::stalecache::data.back());
				iwf::roomcache::stalecache::data.pop_back();
				return 0;
		}} else {
			return -1;
		}}

	SYSINT increment (int64_t input) {
		if (iwf::roomcache::data.contains(input)) {
			if (iwf::roomcache::data.at(input).second < 0) {
				iwf::roomcache::data.at(input).second = 0;
				iwf::roomcache::stalecache::data.remove(input);
				iwf::roomcache::stalecache::index.erase(input);
				return 0;
			} else {
				iwf::roomcache::data.at(input).second += 1;
				if (iwf::roomcache::data.at(input).second < 0) {
					errno = EOVERFLOW;
					return -1;
					}
				return 0;
		}} else {
			iwf::roomcache::data[input].first = iwf::loadroom(input);
			int tmperr = errno;
			if (iwf::roomcache::data.at(input).first == NULL) {
				iwf::roomcache::data.erase(input);
				errno = tmperr;
				return -1;
				}
			return 0;
		}}

	SYSINT decrement (int64 input) {
		if (iwf::roomcache::data.contains(input) {
			if (iwf::roomcache::data.at(input).second < 0) {
				return 0;
			} else {
				iwf::roomcache::data.at(input).second -= 1;
				if (iwf::roomcache::data.at(input).second < 0) {
					iwf::roomcache::queueforunload(input);
					}
				return 0;
				}
		} else {
			errno = EINVAL;
			return -1;
		}}

	SYSINT jump (int64_t input) {
		if (iwf::roomcache::current[3][3][3] == input) {
			errno = EBUSY;
			return 0;
		} else {
		iwf::roomcache::decrement(iwf::roomcache::current[3][3][3]);
		iwf::roomcache::current = 

	SYSINT warp (size_t bankno) {
		int64_t tmp = iwf::roomcache::current[3][3][3];
		iwf::roomcache::current = iwf::roomcache::warpbank[bankno];
		iwf::roomcache::warpbank[bankno] = tmp;
		iwf::roomcache::undowarpbank.push_front(tmp);
		iwf::roomcache::increment(tmp);
		if (iwf::roomcache::undowarpbank.size() > IWF__CHUNKCACHE__UNDOWARP_LEVELS) {
			iwf::roomcache::decrement(iwf::warpcache::undowarpbank.back());
			iwf::roomcache::undowarpbank.pop_back();
			}
		return 0;
		}

	SYSINT warpback () {
		int64_t tmp = iwf::roomcache::current;
		iwf::roomcache::current = iwf::roomcache::undowarpbank.front();
		iwf::roomcache::decrement(tmp);
		iwf::roomcache::undowarpbank.pop_front();
		for (std::vector<int64_t>::iterator i = iwf::roomcache::warpbank.begin();i != iwf::roomcache::warpbank.end;i++) {
			if (i.second == iwf::roomcache::current) {
				i.second = tmp;
				iwf::roomcache::decrement(iwf::roomcache::current);
				iwf::roomcache::increment(tmp);
				}
		return 0;
		}
	}

extern "C" {

	iwf$$scrollroom (char x,char y,char z)


