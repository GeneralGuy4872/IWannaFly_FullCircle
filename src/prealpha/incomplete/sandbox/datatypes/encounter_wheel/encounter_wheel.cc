/* UNDER CONSTRUCTION
 *
 * areas requiring attention are marked ⍝
 */

⍝#include "encounter_wheel.hh"

extern "C" {

	iwf$$datatypes$$encounter_t iwf$$datatype$$encounter_wheel$$next (void * opaque) {
		iwf$$datatype$$encounter_wheel * object = opaque;
		if (object->next >= object->table.size()) {
			object->next = 0;
			}
		iwf$$datatype$$encounter_t output = object->table[object->next];
		object->next += 1;
		return output;
		}

	void iwf$$datatypes$$encounter_wheel$$insert (void * opaque,iwf$$datatype$$encounter_t nova) {
		iwf$$datatype$$encounter_wheel * object = opaque;
		if (object->next >= object->table.size()) {
			object->next = 0;
			object->table.push_back(nova);
		} else {
			object->table.insert(object->table.begin() + object->next,nova);
			object->next += 1;
		}}

	int iwf$$datatypes$$encounter_wheel$$erase (void * opaque,size_t dead) {
		iwf$$datatypes$$encounter_wheel * object = opaque;
		if (dead >= object->table.size()) {
			errno = EFAULT;
			return -1;
		} else {
			object->table.erase(dead);
			if (object->next > dead) {
				object->next -= 1;
		}}}

	}
