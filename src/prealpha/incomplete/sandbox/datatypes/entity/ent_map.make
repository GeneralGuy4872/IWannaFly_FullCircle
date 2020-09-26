IWF_SRC_PATH :=
IWF_TOOLS_PATH :=


$(IWF_SRC_PATH)/datatypes/entity/ent_map.cc : $(IWF_SRC_PATH)/datatypes/entity/ent_typ.h $(IWF_TOOLS_PATH)/stdmapwrapper_codegen.out
$(IWF_TOOLS_PATH)/stdmapwrapper_codegen.out u16 enttyp uint16_t "iwf\$\$datatypes\$\$ent_typ" uint16_t "iwf\$\$datatypes\$\$ent_typ" 0 0 0 "#include \"$(IWF_SRC_PATH)/datatypes/entity/entity.h\"" > $(IWF_SRC_PATH)/datatypes/entity/ent_map.cc

$(IWF_SRC_PATH)/datatypes/entity/ent_map.h : $(IWF_SRC_PATH)/datatypes/entity/ent_typ.h $(IWF_TOOLS_PATH)/stdmapwrapper_headergen.out
$(IWF_TOOLS_PATH)/stdmapwrapper_headergen.out u16 enttyp uint16_t "iwf\$\$datatypes\$\$ent_typ" "#include \"$(IWF_SRC_PATH)/datatypes/entity/entity.h\"" > $(IWF_SRC_PATH)/datatypes/entity/ent_map.h

