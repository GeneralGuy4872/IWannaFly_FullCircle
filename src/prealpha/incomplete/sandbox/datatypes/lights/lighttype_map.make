IWF_SRC_PATH :=
IWF_TOOLS_PATH :=

$(IWF_SRC_PATH)/datatypes/entity/lightbeam_map.cc : $(IWF_SRC_PATH)/datatypes/lights/lighttype.h $(IWF_TOOLS_PATH)/stdmapwrapper_codegen.out
$(IWF_TOOLS_PATH)/stdmapwrapper_codegen.out u16 lightbeam uint16_t "iwf\$\$datatypes\$\$lightbeam_t" uint16_t "iwf\$\$datatypes\$\$lightbeam_t" 0 0 0 "#include \"$(IWF_SRC_PATH)/datatypes/lights/lighttype.h\"" > $(IWF_SRC_PATH)/datatypes/entity/lightbeam_map.cc

$(IWF_SRC_PATH)/datatypes/entity/lightbeam_map.h : $(IWF_SRC_PATH)/datatypes/lights/lighttype.h $(IWF_TOOLS_PATH)/stdmapwrapper_headergen.out
$(IWF_TOOLS_PATH)/stdmapwrapper_headergen.out u16 lightbeam uint16_t "iwf\$\$datatypes\$\$lightbeam_t" "#include \"$(IWF_SRC_PATH)/datatypes/lights/lighttype.h\"" "typedef void * iwf$$datamap$$> $(IWF_SRC_PATH)/datatypes/lights/lightbeam_map.h

$(IWF_SRC_PATH)/datatypes/entity/lightsource_map.cc : $(IWF_SRC_PATH)/datatypes/lights/lighttype.h $(IWF_TOOLS_PATH)/stdmapwrapper_codegen.out
$(IWF_TOOLS_PATH)/stdmapwrapper_codegen.out u16 lightsource uint16_t "iwf\$\$datatypes\$\$lightsource_t" uint16_t "iwf\$\$datatypes\$\$lightsource_t" 0 0 0 "#include \"$(IWF_SRC_PATH)/datatypes/lights/lighttype.h\"" > $(IWF_SRC_PATH)/datatypes/entity/lightsource_map.cc

$(IWF_SRC_PATH)/datatypes/entity/lightsource_map.h : $(IWF_SRC_PATH)/datatypes/lights/lighttype.h $(IWF_TOOLS_PATH)/stdmapwrapper_headergen.out
$(IWF_TOOLS_PATH)/stdmapwrapper_headergen.out u16 lightsource uint16_t "iwf\$\$datatypes\$\$lightsource_t" "#include \"$(IWF_SRC_PATH)/datatypes/lights/lighttype.h\"" > $(IWF_SRC_PATH)/datatypes/lights/lightsource_map.h
