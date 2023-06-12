
var images = [
  "Pictures/a.jpg",
  "Pictures/b.jpg",
  "Pictures/c.png",
  "Pictures/d.jpg",
  "Pictures/e.jpg", 
  "Pictures/f.jpg",
  "Pictures/g.jpg"];

function randImg() {
  var size = images.length
  var x = Math.floor(size * Math.random())
  document.getElementById('image').src = images[x];
}
randImg();