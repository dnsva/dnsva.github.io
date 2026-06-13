
var images = [
  "animal_photos/a.jpg",
  "animal_photos/b.jpg",
  "animal_photos/c.jpg",
  "animal_photos/d.jpg",
  "animal_photos/e.jpg",
  "animal_photos/f.jpg",
  "animal_photos/g.jpg"
];

function randImg() {
  var size = images.length
  var x = Math.floor(size * Math.random())
  document.getElementById('image').src = images[x];
}
randImg();