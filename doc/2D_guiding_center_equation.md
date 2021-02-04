# Guiding Center Equation

reference :: https://agupubs.onlinelibrary.wiley.com/doi/full/10.1029/2010JA015682

cgs gaussian units

$\frac{\partial f}{\partial t}+\vec{v} \cdot \frac{\partial f}{\partial \vec{x}} = 0$

$\vec{v} = c\frac{\vec{D}}{B_\parallel^\ast} \times \vec{b}$

$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial \vec{v_E}}{\partial t}+\nabla \frac{v_E^2}{2})$

$\vec{v_E} =\frac{c\vec{E}}{B} \times \vec{b}$

$\vec{B^\ast} = \vec{B} + \frac{mc}{q}(\nabla\times\vec{v_E})$

$B^\ast_\parallel = \vec{B^\ast} \cdot \vec{b}$

$B = |\vec{B}|$


$\vec{B}(\vec{x}) = \frac{\mu_0}{4\pi}\frac{3(\vec{m_E}\cdot \vec{\hat{x}})\vec{\hat{x}}-\vec{m_E}}{x^3}$

$\vec{\hat{x}}=\frac{\vec{x}}{|x|}$

Below We use cylindrical coordinates

$\vec{x} = (r,\theta,z)$

$\nabla f=\frac{\partial f}{\partial r}\vec{e_r} + \frac{1}{r}\frac{\partial f}{\partial \theta}\vec{e_\theta} + \frac{\partial f}{\partial z}\vec{e_z}$

$\nabla \cdot \vec{A}=\frac{1}{r}(\frac{\partial (rA_r)}{\partial r} + \frac{\partial A_\theta}{\partial \theta} + r\frac{\partial A_z}{\partial z})$

$\nabla \times \vec{A}=(\frac{1}{r}\frac{\partial A_z}{\partial \theta}-\frac{\partial A_\theta}{\partial z})\vec{e_r} + (\frac{\partial A_r}{\partial z}+\frac{\partial A_z}{\partial r})\vec{e_\theta} + \frac{1}{r}(\frac{\partial (rA_\theta)}{\partial r}-\frac{\partial A_r}{\partial \theta})\vec{e_z}$

Toroidal mode wave

ULF waves

$\vec{B}_{wave} = \vec{e _{\theta}}B_Asin(\omega(t-\frac{r\theta}{v_a}))$

$ =\vec{e_\theta} B_Asin(m\omega_d(t-\frac{r\theta}{v_a}))$

$=\vec{e_\theta} B_Asin(m2\pi(\frac{t}{T}-\frac{r\theta}{\lambda}))$

$\vec{E}_{wave} = \vec{e_r} E_Asin(m2\pi(\frac{t}{T}-\frac{r\theta}{\lambda})+\frac{\pi}{2})$

$E_{wave} =E_Asin(m2\pi(\frac{t}{T}-\frac{r\theta}{\lambda})+\frac{\pi}{2})$


$\vec{E}_{wave} = \vec{e_r} E_{wave}$

$\vec{B_0}= \frac{\mu_0}{4\pi}\frac{3(\vec{m}\cdot \vec{\hat{x}})\vec{\hat{x}}-\vec{m}}{|\vec{x}|^3}$


$\vec{m} = m\vec{e_z}$

$\vec{B_0} = \frac{\mu_0}{4\pi}\frac{3mz \vec{\hat{x}}-m \vec{e_z} }{|\vec{x}|^3}$


$\vec{E_0} = \vec{0}$

$\vec{E} = \vec{E_0}+\vec{E}_{wave} = \vec{E} _{wave}$

$\vec{B} = \vec{B_0}+\vec{B}_{wave}$





Apply to the fomula

$\vec{v_E} =\frac{\vec{cE}}{B} \times \vec{b}$

$=\frac{c\vec{E} _{wave}}{|B|^2}\times \vec{B}$

$\vec{B^\ast} = \vec{B} + \frac{mc}{q}(\nabla\times\vec{v_E})$

$= \vec{B}+\frac{mc}{q}(\nabla \times (\frac{c\vec{E} _{wave}}{|B|^2}\times \vec{B}))$

$= \vec{B}+\frac{mc}{q}((\nabla \cdot \vec{B})\frac{c\vec{E} _{wave}}{|B|^2} - (\nabla \cdot \frac{c\vec{E} _{wave}}{|B|^2}) \vec{B})$

$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial \vec{v_E}}{\partial t}+\nabla \frac{v_E^2}{2})$

$= \vec{E}_{wave}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial}{\partial t}(\frac{c\vec{E} _{wave}}{|B|^2}\times \vec{B})+\frac{1}{2}\nabla|\frac{c\vec{E} _{wave}}{|B|^2}\times \vec{B}|^2)$

Assumption 
- $\vec{B}_{wave}<<\vec{B_0}$
- $\frac{\partial B_z}{\partial z}= 0$
- $\frac{\partial B_r}{\partial z}= 0$

so,


- $\vec{B} = \vec{B_0}$

- $\frac{\partial \vec{B}}{\partial t} = \vec{0}$
- $\vec{B} = (B_r,B_\theta,B_z) = (0,0,B_z)$
- $\frac{\partial \vec{B}}{\partial r} = (0,0,\xi_r)$
- $\frac{\partial \vec{B}}{\partial \theta} = (0,0,0)$
- $\frac{\partial \vec{B}}{\partial z} = (0,0,0)$
- $\vec{b} = \vec{e_z}$

$B^\ast= \vec{B}+\frac{mc}{q}((\nabla \cdot \vec{B})\frac{c\vec{E} _{wave}}{|B|^2} - (\nabla \cdot \frac{c\vec{E} _{wave}}{|B|^2}) \vec{B})$


$ = B_z\vec{e_z}+\frac{mc}{q}(- (\nabla \cdot \frac{c\vec{E} _{wave}}{B_z^2}) B_z\vec{e_z})$

$ = B_z\vec{e_z}+\frac{mc}{q}( - (\frac{\partial}{\partial r} \frac{cE _{wave}}{B_z^2}) B_z\vec{e_z})$

$ = B_z\vec{e_z}+\frac{mc}{q}(cE _{wave}(\frac{2B_z\xi_r}{B_z^4}) B_z\vec{e_z})$


$ = B_z\vec{e_z}+\frac{mc}{q}(cE _{wave}\frac{2\xi_r}{B_z^2}) \vec{e_z}$

$ = (B_z+\frac{mc^2}{q}E _{wave}\frac{2\xi_r}{B_z^2}) \vec{e_z}$

$B^\ast_\parallel = B_z+\frac{mc^2}{q}E _{wave}\frac{2\xi_r}{B_z^2}$


$\vec{D} = \vec{E}_{wave}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(c\frac{\partial\vec{E} _{wave}}{\partial t}\times\frac{ \vec{B}}{|B|^2}+\frac{1}{2}\nabla|c\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B}|^2)$

$= \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(\frac{\partial (\vec{e_r} E_{wave})}{\partial t}\times\frac{ \vec{e_z}}{B_z}+\frac{c}{2}\nabla|\frac{\vec{e_r} E_{wave}}{B_z^2}\times B_z\vec{e_z}|^2)$



$ = \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(-\frac{\partial E_{wave}}{\partial t}\frac{1}{B_z}\vec{e_\theta}+\frac{c}{2}\nabla|-\frac{E_{wave}}{B_z^2}B_z\vec{e_\theta}|^2)$



$ = \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(-\frac{\partial E_{wave}}{\partial t}\frac{1}{B_z}\vec{e_\theta}+\frac{c}{2}\nabla((\frac{E_{wave}}{B_z^2}B_z)^2))$

$ = \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(-\frac{\partial E_{wave}}{\partial t}\frac{1}{B_z}\vec{e_\theta}+c\frac{E_{wave}}{B_z}\nabla(\frac{E_{wave}}{B_z}))$

$ = \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(-\frac{\partial E_{wave}}{\partial t}\frac{1}{B_z}\vec{e_\theta}+c\frac{E_{wave}}{B_z}\frac{E_{wave}\nabla B_z+B_z\nabla E_{wave}}{B_z^2})$

$ = \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(-\frac{\partial E_{wave}}{\partial t}\frac{1}{B_z}\vec{e_\theta}+c\frac{E_{wave}}{B_z}\frac{E_{wave}\xi_r\vec{e_r}}{B_z^2}+c\frac{E_{wave}}{B_z}\frac{\nabla E_{wave}}{B_z})$

$ = \vec{e_r} E_{wave}-\frac{\mu}{q}\xi_r\vec{e_r} - \frac{mc}{q}(-\frac{\partial E_{wave}}{\partial t}\frac{1}{B_z}\vec{e_\theta}+c\frac{E^2_{wave}\xi_r}{B_z^3}\vec{e_r}+c\frac{E_{wave}}{B_z^2}\frac{\partial E_{wave}}{\partial \theta}\vec{e_\theta})$
($E_{wave} = E_{wave}(\theta)$)

$=(E_{wave}-\frac{\mu}{q}\xi_r-\frac{mc^2}{q}\frac{E^2_{wave}\xi_r}{B_z^3})\vec{e_r}+\frac{m}{q}(\frac{\partial E_{wave}}{\partial t}\frac{c}{B_z}-c^2\frac{E_{wave}}{B_z^2}\frac{\partial E_{wave}}{\partial \theta})\vec{e_\theta}$


$\vec{v} = \frac{\vec{D}}{B_\parallel^\ast} \times \vec{b}$

$\vec{v} =  (B_z+\frac{mc^2}{q}E _{wave}\frac{2\xi_r}{B_z^2})^{-1}(-(E_{wave}-\frac{\mu}{q}\xi_r-\frac{mc^2}{q}\frac{E^2_{wave}\xi_r}{B_z^3})\vec{e_\theta}+\frac{m}{q}(\frac{\partial E_{wave}}{\partial t}\frac{c}{B_z}-c^2\frac{E_{wave}}{B_z^2}\frac{\partial E_{wave}}{\partial \theta})\vec{e_r})$