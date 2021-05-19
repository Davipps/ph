#define MAX_DROPS_ITEMS			3000

enum dItemInfo 
{
    dit_ID,
    dit_area,
    dit_object,
    dit_ammon,
    bool:dit_valid
};
new d_Items[MAX_DROPS_ITEMS][dItemInfo],
	TOTAL_DROPS;