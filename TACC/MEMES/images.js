
var images = [
    "MEMES/1.jpg",
    "MEMES/2.jpg",
    "MEMES/3.jpg",
    "MEMES/4.png",
    "MEMES/5.png",
    "MEMES/6.png",
    "MEMES/7.jpg",
    "MEMES/8.png",
    "MEMES/9.png",
    "MEMES/10.jpg",
    "MEMES/11.png",
    "MEMES/12.png",
    "MEMES/13.png",
    "MEMES/14.jpg"
];
  
  function randImg() {
    var size = images.length
    var x = Math.floor(size * Math.random())
    document.getElementById('image').src = images[x];
  }
  randImg();
