#define JS0 _IOR('j',0,struct js_event);

#include <linux/joystick.h>

extern volatile ATOMIC(bool) HALT;
extern volatile ATOMIC(bool) ERROR;
extern volatile ATOMIC(bool) CHANGE_JSDEV;

std::vector<ATOMIC(bool)> iwf::joystick::buttons;
std::vector<ATOMIC(int16_t)> iwf::joystick::axes;

#define MAPPED_BUTTONS_MAX 8
#define MAPPED_AXES_MAX 11

unsigned char iwf$$iosettings$$buttonmap[MAPPED_BUTTONS_MAX];
unsigned char iwf$$iosettings$$axismap[MAPPED_AXES_MAX];
unsigned char iwf$$iosettings$$sensitivity;

extern "C" {

iwf$$joystickio (void * dummy) {
	for (;!(HALT || ERROR);) {
		if ((jsdev = open(iwf::iosettings::jsdevpath.c_str(),O_RDONLY | O_NONBLOCK)) < 0) {
			HALT = 1;
			ERROR = 1;
			return 1;
			}
		{
			unsigned char axes;
			ioctrl(jsdev,JSIOCGAXES,&axes);
			iwf::irq::axes.reserve(axes);
		}{
			unsigned char buttons;
			ioctrl(jsdev,JSIOCGBUTTONS,&buttons);
			iwf::irq::axes.reserve(buttons);
			}
		js_event js;
		while (!CHANGE_JSDEV) {
			read(jsdev,&js,sizeof(struct js_event));
			switch (js.type) {
				case JS_EVENT_BUTTON :
					if ((js.number + 1) > iwf::irq::buttons.capacity()) {
						iwf::irq::buttons.reserve(js.number + 1);
						}
					iwf::irq::buttons[js.number] = js.value;
					break;
				case JS_EVENT_AXIS :
					if ((js.number + 1) > iwf::irq::axis.capacity()) {
						iwf::irq::axis.reserve(js.number + 1);
						}
					iwf::irq::axis[js.number] = js.value & invbase1(int16_t,iwf$$iosettings$$sensitivity);
					if (iwf::irq::axis[js.number] && iwf$$iosettings$$sensitivity) {
						js.value | base1(iwf$$iosettings$$sensitivity);
						};
					break;
				default : break;
			}
		close(jsdev);
		}
	}}

bool iwf$$joystick$$getbutton (unsigned char index) {
	if (index < MAPPED_BUTTONS_MAX) {
		return iwf::joystick::buttons[iwf$$iosettings$$buttonmap[index]];
	} else {
		errno = EINVAL;
		return 0;
	}}

int16_t iwf$$joystick$$getaxis (unsigned char index) {
	if (index < MAPPED_AXES_MAX) {
		return iwf::joystick::axes[iwf$$iosettings$$axismap[index]];
	} else {
		errno = EINVAL;
		return 0;
	}}

#define REMAP_X0 0
#define REMAP_Y0 1
#define REMAP_LT 2
#define REMAP_X1 3
#define REMAP_Y1 4
#define REMAP_RT 5
#define REMAP_XPAD 6
#define REMAP_YPAD 7

#define REMAP_A 0
#define REMAP_B 1
#define REMAP_X 2
#define REMAP_Y 3
#define REMAP_LB 4
#define REMAP_RB 5
#define REMAP_BACK 6
#define REMAP_START 7
#define REMAP_BIGX 8
#define REMAP_LSTICK 9
#define REMAP_RSTICK 10

extern volatile ATOMIC(uint8_t) iwf$$settings$$desense;

iwf$$buttonmap$$assign (



			read(joystick,&event1,sizeof(event1));
			if (event1.type == 0x02)
				{
				values[event1.number] = event1.value;
				}
			}
		while (*JSAXISFLAG == 0)
			{
			sleep(0);
			}
		*JSAXISFLAG = -1;
		(*JSAXISBUFF)[0] = values[0];
		(*JSAXISBUFF)[1] = values[1];
		(*JSAXISBUFF)[2] = values[2];
		(*JSAXISBUFF)[3] = values[3];
		(*JSAXISBUFF)[4] = values[4];
		(*JSAXISBUFF)[5] = values[5];
		(*JSAXISBUFF)[6] = values[6];
		(*JSAXISBUFF)[7] = values[7];
		*JSAXISFLAG = 0;
		}
