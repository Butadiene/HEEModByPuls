<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>
## only vscode??(for tex)
# Parameter standardization

Definition

$c$ : lightspeed

$m = m_e m^\ast$

$q = q_e q^\ast$

$\Omega_e = \frac{q_e}{m}B_{eq}$ : Electron cyclotron frequency

$v = cv^\ast$

$x = c \Omega_e^{-1}x^\ast$

$\vec{B} = B_{eq}\vec{B^\ast}$

$\vec{E} = cB_{eq}\vec{E^\ast}$

$t = \Omega_e^{-1}t^\ast$

so,

$\frac{dx}{dt} = v = cv^\ast$

$\frac{d(c\Omega_e^{-1}x^\ast)}{d(\Omega_e^{-1}t^\ast)} = c v^\ast$

$c\frac{dx^\ast}{dt^\ast} = c v^\ast$

$\frac{dx^\ast}{dt^\ast} = v^\ast$

$\frac{dv}{dt}=q_e(\vec{E}+\vec{v}\times \vec{B}) $

$\frac{dv}{dt}=\frac{d(c\cdot v^\ast)}{d(\Omega_e^{-1}t^\ast)} = c\Omega_e \frac{dv^\ast}{dt^\ast}$

$c\Omega_e\frac{dv^\ast}{dt^\ast}=q_e(\vec{E}+\vec{v}\times\vec{B})$


$\frac{dv^\ast}{dt^\ast}=\frac{cm}{q_eB_{eq}}q_e(\vec{E}+\vec{v}\times\vec{B})$

$\frac{dv^\ast}{dt^\ast}=\vec{E^\ast}+\vec{v^\ast}\times\vec{B^\ast}$