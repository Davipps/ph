enum itemsInfo
{
	it_id,
	it_object,
	it_slot,
	Float:it_weigth,
	it_name[30]
};

new const items[][itemsInfo] = {
	{0, 0, 0, 0.0, "Nada"},
	{1, 311, 0, 0.1, "Manopla"},
	{2, 333, 1, 0.6, "Palo de golf"},
	{3, 334, 1, 0.5, "Porra policial"},
	{4, 335, 1, 0.3, "Cuchillo"},
	{5, 336, 1, 0.5, "Bate de baseball"},
	{6, 337, 1, 0.9, "Pala"},
	{7, 338, 1, 0.4, "Palo de pool"},
	{8, 339, 1, 0.4, "Katana"},
	{9, 341, 1, 2.3, "Motosierra"},
	{10, 321, 10, 0.2, "Dildo violeta"},
	{11, 322, 10, 0.2, "Dildo"},
	{12, 323, 10, 0.3, "Vibrador"},
	{13, 324, 10, 0.3, "Vibrador gris"},
	{14, 325, 10, 0.3, "Flores"},
	{15, 326, 10, 0.4, "Baston"},
	{16, 342, 8, 0.1, "Granada"},
	{17, 343, 8, 0.1, "Bomba de humo"},
	{18, 344, 8, 0.2, "Molotov"},
	{19, 0, 0, 0.0, ""},
	{20, 0, 0, 0.0, ""},
	{21, 0, 0, 0.0, ""},
	{22, 346, 2, 0.9, "9mm"},
	{23, 347, 2, 1.0, "9mm con silenciador"},
	{24, 348, 2, 1.5, "Desert Eagle"},
	{25, 349, 3, 3.2, "Escopeta"},
	{26, 350, 3, 1.7, "Escopeta recortada"},
	{27, 351, 3, 4.2, "Escopeta de Combate"},
	{28, 352, 4, 2.0, "Uzi"},
	{29, 353, 4, 3.6, "MP5"},
	{30, 355, 5, 4.8, "AK-47"},
	{31, 356, 5, 4.9, "M4"},
	{32, 372, 4, 2.1, "Tec-9"},
	{33, 357, 6, 3.7, "Rifle"},
	{34, 358, 6, 4.7, "Rifle de francotirador"},
	{35, 359, 7, 6.4, "RPG"},
	{36, 360, 7, 7.0, "RPG busca calor"},
	{37, 361, 7, 7.1, "Lanza llamas"},
	{38, 362, 7, 7.2, "Minigun"},
	{39, 363, 8, 1.6, "Carga explosiva"},
	{40, 364, 12, 0.3, "Detonador"},
	{41, 365, 9, 0.4, "Espray"},
	{42, 366, 9, 2.4, "Extintor"},
	{43, 367, 9, 0.3, "Camara"},
	{44, 368, 11, 0.02, "Lentes de vision nocturna"},
	{45, 369, 11, 0.02, "Lentes termicos"},
	{46, 371, 11, 4.0, "Paracaidas"},

	{48, 2969, -1, 0.5, "Vendas"}
};