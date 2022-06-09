// This function exists to universally reclaculate length for reallocation.
// This enables us to use a common algorithm for recalculating vector length.
// Used mainly by coord_vec, but also by other functions.
long base_recalc_cap(long old_l);
