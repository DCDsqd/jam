#ifndef PARAM_BUTTON_H
#define PARAM_BUTTON_H

#include <godot_cpp/classes/button.hpp>

namespace godot {

class ParamButton : public Button {
	GDCLASS(ParamButton, Button)

protected:
	static void _bind_methods();
    int num = 0;

public:
	void set_num(int p_num);

    void _pressed() override;

	ParamButton();
	~ParamButton();
};

}

#endif //PARAM_BUTTON_H