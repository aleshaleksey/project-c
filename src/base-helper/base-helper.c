long base_recalc_cap(long old_l) {
  if(old_l < 1024) {
    return old_l * 2;
  } else {
    return old_l + old_l / 4;
  }
}
