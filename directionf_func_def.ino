void idle() {
  fl.kill();
  fr.kill();
  bl.kill();
  br.kill();
}

//Translations

void north(int n) {
  fl.forward(n);
  fr.forward(n);
  bl.forward(n);
  br.forward(n);
}

void south(int n) {
  fl.backward(n);
  fr.backward(n);
  bl.backward(n);
  br.backward(n);
}

void east(int n) {
  fl.forward(n);
  fr.backward(n);
  bl.backward(n);
  br.forward(n);
}

void west(int n) {
  fl.backward(n);
  fr.forward(n);
  bl.forward(n);
  br.backward(n);
}

void northeast(int n) {
  fl.forward(n);
  br.forward(n);
}

void northwest(int n) {
  fr.forward(n);
  bl.forward(n);
}

void southeast(int n) {
  fr.backward(n);
  bl.backward(n);
}

void southwest(int n) {
  fl.backward(n);
  br.backward(n);
}

// Rotations

void clockwise(int n) {
  fl.forward(n);
  bl.forward(n);
  fr.backward(n);
  br.backward(n);
}

void anticlockwise(int n) {
  fl.backward(n);
  bl.backward(n);
  fr.forward(n);
  br.forward(n);

}
