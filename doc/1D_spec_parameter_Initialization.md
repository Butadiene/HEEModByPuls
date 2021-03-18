# Spec Parameter standardization and Initialization

Definition

$c$ : lightspeed

$c =  2.99792458×10^{10}$cm/s

$m = m_e m^\ast$

$m_e = 9.10938356×10^{-28}$g 

$m^* = 1$

$q = q_e q^\ast$

$q_e = 4.8*10^{-10}$ Fr

$q^* = 1$

$v = cv^\ast$

$T$ ULF wave period

$T = 100$ s

$x = c Tx^\ast$

$\vec{B} = B_{eq}\vec{B^\ast}$

$\vec{E} = B_{eq}\vec{E^\ast}$

Here, it is assumed that $B_{eq}$ is the equatorial magnetic field in the Lshell of interest.
That's mean $B_{eq}(L)$

$R_0 = 6371$km $\approx 6.4*10^3$km $=6.4*10^8$cm


$\lambda = \frac{L*R_0*2\pi}{m_{number}}$

$t = Tt^\ast$   


$\frac{\partial B_z}{\partial r} = \xi_r$


$\frac{\partial (B_z^\ast B_{eq})}{\partial (cTr^\ast)} = \frac{ B_{eq}}{cT}\frac{\partial B_z^\ast}{\partial r^\ast}  =  \frac{ B_{eq}}{cT}\xi_r^\ast = \xi_r$


$B = \frac{B_E}{L^3}\frac{(1+3\sin^2\Lambda)^
{\frac{1}{2}}}{\cos^6\Lambda}$(from:Basic Space Plasma Physics)
($B_E = 3.11*10^{-5}$T $=3.11*10^{-1}$G)

when $\Lambda = 0$,

$B_{eq} = \frac{B_E}{L^3}$

$\xi_r^\ast = \xi_r \frac{cT}{B_{eq}} = \frac{\partial B_z}{\partial L} \frac{\partial L}{\partial r}\frac{cT}{B_{eq}} =  \frac{\partial B_z}{\partial r} \frac{cT}{B_{eq}} \frac{\partial L}{\partial r}= -3\frac{B_E}{L^4} \frac{cTL^3}{B_E}\frac{\partial L}{\partial r} = -3\frac{cT}{L}\frac{\partial L}{\partial r}$

$r = LR_0$

$\xi_r^\ast = -3\frac{cT}{L}\frac{1}{R_0}$

$\mu = \frac{mv_\perp^2}{2B} = \frac{m^\ast m_e c^2 v^{\ast 2}_\perp }{2B^\ast B_{eq}} = \frac{c^2m_e}{B_{eq}}\mu^\ast$


$E_A = 4$mV/m $ = 4*10^{-3}$V/m = $4*10^{-3}*10^6 c^{-1}$statV/cm $= 4*10^3c^{-1}$statV/cm

$\vec{v} =  -\{B_z^\ast+\frac{m^\ast}{q^\ast}\frac{\xi_r^\ast }{T \Omega_e }(\frac{E^\ast_A }{(B_z^\ast )^2}\sin\{2\pi(t^\ast-\frac{R_0\theta}{\lambda})+\frac{\pi}{2}\})\}^{-1}(E^\ast_A\sin\{2\pi(t^\ast-\frac{R_0\theta}{\lambda})+\frac{\pi}{2}\}-\frac{\mu^\ast}{  q^\ast}\frac{\xi_r^\ast}{T \Omega_e}+\frac{m^\ast c}{q^\ast}\frac{1}{(B_z^\ast)^3}\frac{\xi_r^\ast}{T \Omega_e}(E^\ast_A\sin\{2\pi(t^\ast-\frac{R_0\theta}{\lambda})+\frac{\pi}{2}\})^2 )\vec{e_\theta}$