/* NOTE: this program requires an rlights.h implementation to be compiled
 * and linked to it. as of 13 March, 2020, two such implementations exist
 * in the examples directory of Raylib. I am unaware of precedant to do
 * this, however in versions of Raylib prior to 1.7.0, these functions were
 * part of the core library.
 *
 * this is a binding for code belonging to
 * Victor Fisac (@victorfisac) and Ramon Santamaria (@raysan5),
 * produced by transcribing relevant data.
 *
 * the code was made avalible under the following liscense:
 *
 *	This software is provided "as-is", without any express or implied warranty. In no event
 *	will the authors be held liable for any damages arising from the use of this software.
 *
 *	Permission is granted to anyone to use this software for any purpose, including commercial
 *	applications, and to alter it and redistribute it freely, subject to the following restrictions:
 *
 *	1. The origin of this software must not be misrepresented; you must not claim that you
 *	   wrote the original software. If you use this software in a product, an acknowledgment
 *	   in the product documentation would be appreciated but is not required.
 *
 *      2. Altered source versions must be plainly marked as such, and must not be misrepresented
 *	   as being the original software.
 *
 *      3. This notice may not be removed or altered from any source distribution.
 */

#ifndef RLIGHTS_H
#define RLIGHTS_H

#define MAX_LIGHTS 4

typedef struct {   
	int type;
	Vector3 position;
	Vector3 target;
	Color color;
	bool enabled;

	int enabledLoc;
	int typeLoc;
	int posLoc;
	int targetLoc;
	int colorLoc;
	} Light;

typedef enum {
	LIGHT_DIRECTIONAL,
	LIGHT_POINT
	} LightType;

Light CreateLight(int type, Vector3 position, Vector3 target, Color color, Shader shader);
void UpdateLightValues(Shader shader, Light light);

#endif
