tilemeta * roomtileget(roomtyp * this,tileset * maintiles,ucoord pos) {
	div_t x = div(pos[0],CHUNK);
	div_t y = div(pos[1],CHUNK);
	div_t z = div(pos[2],CHUNK);
	if ((x.quot > this->size.x) || (y.quot > this->size.y) || (z.quot > this->size.z)) {
		return NULL;
		}
	else if (this->chunks[SUBSCRV(this->size.y,this->size.x,z.quot,y.quot,x.quot)]->tiledata[z.rem][y.rem][x.rem] < 0) {
		return &( maintiles[this->swapin->tiledata[z.rem][y.rem][x.rem]] );
		}
	else {
		return &( this->hightiles[this->tiledata[z.rem][y.rem][x.rem] ^ 0x80] );
		}
	}

tilemeta * roomtilegeti(roomtyp * this,tileset * maintiles,int xx,int yy,int zz) {
	div_t x = div(xx,CHUNK);
	div_t y = div(yy,CHUNK);
	div_t z = div(zz,CHUNK);
	if ((x.quot > this->size.x) || (y.quot > this->size.y) || (z.quot > this->size.z)) {
		return NULL;
		}
	else if (this->chunks[SUBSCRV(z.quot,y.quot,x.quot,this->size.y,this->size.x)]->tiledata[z.rem][y.rem][x.rem] < 0) {
		return &( maintiles[this->swapin->tiledata[z.rem][y.rem][x.rem]] );
		}
	else {
		return &( this->hightiles[this->tiledata[z.rem][y.rem][x.rem] ^ 0x80] );
		}
	}
