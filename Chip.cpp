Chip::Chip(Player *p, int c, int r){
	owner = p;
	col = c;
	row = r;
}

Player* Chip::getOwner(){
	return owner;
}