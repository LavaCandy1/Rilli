const observer = new IntersectionObserver((entries) => {
  entries.forEach((entry) => {
    console.log(entry);
    if (entry.isIntersecting) {
      entry.target.classList.add("show");
    } else {
      entry.target.classList.remove("show");
    }
  });
});

const hiddenElements = document.querySelectorAll(".hidden");
hiddenElements.forEach((el) => observer.observe(el));
const items = document.querySelectorAll(".accordion button");

document.addEventListener("DOMContentLoaded", (event) => {
  gsap.registerPlugin(ScrollTrigger, Observer);

  ScrollTrigger.create({
    animation: gsap.from(".LG", {
      y: "78vh",
      fontSize: "660px",
      yPercent: -70,
    }),
    scrub: true,
    trigger: ".contentVid",
    start: "top bottom",
    endTrigger: ".contentVid",
    end: "top center",
  });

  const myText1 = new SplitType("#myGSAP1");
  const myText2 = new SplitType("#myGSAP2");
  const myText3 = new SplitType("#myGSAP3");
  const myText4 = new SplitType("#myGSAP4");
  const myText5 = new SplitType("#myGSAP5");
  // const myText2 = new SplitType("#myGSAP2");
  // const myText3 = new SplitType("#myGSAP3");
  // const myText4 = new SplitType("#myGSAP4");
  // const myText5 = new SplitType("#myGSAP5");
  // const myText6 = new SplitType("#myGSAP6");
  let t1 = gsap.timeline({
    scrollTrigger: {
      trigger: ".char",
      start: "35% 95%",
      end: "40% 95%",
    },
  });
  t1.to(".char", {
    y: 0,
    stagger: 0.03,
    duration: 0.3,
  });
  let t2 = gsap.timeline({
    scrollTrigger: {
      trigger: ".Anim",
      start: "35% 95%",
      end: "40% 95%",
    },
  });
  t2.to(".Anim", {
    y: 0,
    stagger: 0.1,
    duration: 0.3,
  });
});
// const lenis = new Lenis();

// lenis.on("scroll", (e) => {
//   console.log(e);
// });

// function raf(time) {
//   lenis.raf(time);
//   requestAnimationFrame(raf);
// }

// requestAnimationFrame(raf);

gsap.from(".clip-top, .clip-bottom", 2, {
  delaY: 1,
  height: "50vh",
  ease: "power4.inOut",
});

gsap.to(".marquee", 3.5, {
  delay: 0.75,
  top: "50%",
  ease: "power4.inOut",
});
gsap.from(".clip-top .marquee .clip-bottom .marquee", 5, {
  delay: 1,
  left: "100%",
  ease: "power3.inOut",
});

gsap.from(".clip-center .marquee ", 5, {
  delay: 1,
  left: "-50%",
  ease: "power3.inOut",
});
gsap.to(".clip-top", 2, {
  delay: 6,
  clipPath: "inset(0 0 100% 0)",
  ease: "power4.inOut",
});

gsap.to(".clip-bottom", 2, {
  delay: 6,
  clipPath: "inset(100% 0 0 0)",
  ease: "power4.inOut",
});

gsap.to(
  ".clip-top .marquee, .clip-bottom .marquee, .clip-center .marquee span",
  1,
  {
    delay: 6,
    opacity: 0,
    ease: "power2.inOut",
  }
);

// Fade out loader after 5 seconds
gsap.to(".loader", {
  delay: 7,
  duration: 1,
  opacity: 0,

  onComplete: () => {
    // Remove loader from DOM
    document.querySelector(".loader").remove();
  },
});

function toggleAccordion() {
  const itemToggle = this.getAttribute("aria-expanded");

  for (i = 0; i < items.length; i++) {
    items[i].setAttribute("aria-expanded", "false");
  }

  if (itemToggle == "false") {
    this.setAttribute("aria-expanded", "true");
  }
}
