/* SPDX-License-Identifier: GPL-2.0-only
 
 mrwizardwizard's github
 https://github.com/mrwizardwizard
 
 mrwizardwizards TCP bypass
 TCP bypass is a congestion control bypass for linux. */

#include <linux/module.h>
#include <net/tcp.h>

/* tcp_congestion_ops function calls. */

static inline void tcp_bypass_in_ack_event(struct sock *sk, u32 flags) {
}

static inline void tcp_bypass_pkts_acked(struct sock *sk, const struct ack_sample *sample) {
}

static inline void tcp_bypass_cong_control(struct sock *sk, u32 ack, int flag, const struct rate_sample *rs) {
}

static inline void tcp_bypass_cwnd_event(struct sock *sk, enum tcp_ca_event ev) {
}

static inline u32 tcp_bypass_sndbuf_expand(struct sock *sk) {

	return 0;
}

static inline void tcp_bypass_set_state(struct sock *sk, u8 new_state) {
}

static inline u32 tcp_bypass_ssthresh(struct sock *sk) {

	return 0;
}

static inline u32 tcp_bypass_redo_cwnd(struct sock *sk) {

	struct tcp_sock *tp = tcp_sk(sk);
	
	tp->prior_cwnd = 4294967295;
	tp->snd_cwnd = 4294967295;

	return 1;
}

static inline void tcp_bypass_init(struct sock *sk) {

	struct tcp_sock *tp = tcp_sk(sk);

	/* Set TCP socket variables */

	sk->sk_reserved_mem = 4194304;

	tp->nonagle = 1;
	tp->thin_lto = 0;
	tp->frto = 0;
	tp->snd_ssthresh = 4294967295;
	tp->snd_cwnd = 4294967295;
	tp->snd_cwnd_clamp = 4294967295;
	tp->reordering = 0;
	tp->prior_cwnd = 4294967295;
	tp->prior_ssthresh = 4294967295;
}

static inline void tcp_bypass_release(struct sock *sk) {
}

static inline void tcp_bypass_cong_avoid(struct sock *sk, u32 ack, u32 acked) {
}

static inline size_t tcp_bypass_get_info(struct sock *sk, u32 ext, int *attr, union tcp_cc_info *info) {

	return 0;
}

static struct tcp_congestion_ops tcp_bypass __read_mostly = {
	.in_ack_event	= tcp_bypass_in_ack_event,
	.pkts_acked	= tcp_bypass_pkts_acked,
	.cong_control   = tcp_bypass_cong_control,
	.cwnd_event	= tcp_bypass_cwnd_event,
	.sndbuf_expand	= tcp_bypass_sndbuf_expand,
	.set_state	= tcp_bypass_set_state,
	.ssthresh	= tcp_bypass_ssthresh,
	.undo_cwnd	= tcp_bypass_redo_cwnd,
	.init		= tcp_bypass_init,
	.release	= tcp_bypass_release,
	.name		= "bypass",
	.flags		= TCP_CONG_NON_RESTRICTED,
	.owner		= THIS_MODULE,
	.cong_avoid	= tcp_bypass_cong_avoid,
	.get_info	= tcp_bypass_get_info,
};

static inline int __init tcp_bypass_register(void)
{
	return tcp_register_congestion_control(&tcp_bypass);
}

static inline void __exit tcp_bypass_unregister(void)
{
	tcp_unregister_congestion_control(&tcp_bypass);
}

module_init(tcp_bypass_register);
module_exit(tcp_bypass_unregister);

MODULE_AUTHOR("mrwizardwizard");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TCP Bypass");
